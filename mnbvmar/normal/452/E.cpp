#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>
#define MP make_pair
#define FF first.first
#define FS first.second
#define SF second.first
#define SS second.second
#define ALL(container) (container).begin(), (container).end()
#define FORI(i,from,to) for(int i = (from); i <= (to); i++)
#define FORD(i,from,to) for(int i = (from); i >= (to); i--)
#define REP(i,num) for(int i = 0; i < (num); i++)


using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
const LD Eps = 1e-8;
inline bool is_zero(LD x){ return (x >= -Eps) && (x <= Eps); }


/* sorry :P */
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
//#include <unordered_map>
#include <map>

using namespace std;


class UkkonenTree {
public:
	static const int Infty = 1010101010,
	                 Root = 0,
	                 None = -1;
	
	struct UkkonenNode {
		int start, end; // [start, end)
		int suffixLink;
		int sizChild;
		/*unordered_*/map<char, int> nextNode;
		
		UkkonenNode(int _start=0, int _end=Infty){
			suffixLink = -1;
			start = _start;
			end = _end;
			sizChild = 0;
		}
		int size(int pos){
			return min(pos+1, end) - start;
		}
	};
	
	vector<UkkonenNode> nodes;
	typedef map<char,int>::iterator NodeIter;
	
	int activeNode, activeEdge, activeLen;
	int remainder, position;
	int needSuffix, totalLength;
	char *text;
	
	char char_active_edge(){
		return text[activeEdge];
	}
	
	int create_node(int start, int end){
		UkkonenNode U(start, end);
		nodes.push_back(U);
		return nodes.size()-1;
	}
	
	void process_suffix_link(int node){
		if(node == Root) node = None;
		
		if(needSuffix != None)
			nodes[needSuffix].suffixLink = node;
		needSuffix = node;
	}
	
	
	void dfs_tree(int node, int depth, vector<LL> &res){
		if(node != Root){
			depth += nodes[node].size(totalLength);
		}
		if(nodes[node].end == Infty){
			nodes[node].sizChild = 1;
		} else {
			nodes[node].sizChild = 0;
			map<char,int> &nnodes = nodes[node].nextNode;
			for(NodeIter it = nnodes.begin(); it != nnodes.end(); it++){
				dfs_tree(it->second, depth, res);
				nodes[node].sizChild += nodes[it->second].sizChild;
			}
			if(node != Root){
				int k = nodes[node].sizChild;
				LL kres = (((LL)(k) * (k-1)) * (k-2)) / 6;
				int beg = depth-nodes[node].size(totalLength);
				//printf("T %d %d %d\n", depth-nodes[node].size(totalLength), depth, k);
				res[beg+1] += kres;
				res[depth+1] -= kres;
			}
		}
	}
	


//public:
	UkkonenTree(int len){
		nodes.resize(1);
		nodes.reserve(len+1);
		nodes[Root] = UkkonenNode(None, None);
		
		activeNode = Root;
		activeEdge = None;
		activeLen = 0;
		remainder = 0;
		position = 0;
		needSuffix = None;
		totalLength = len;
		text = new char[len+1];
	}
	
	~UkkonenTree(){
		delete text;
	}
	
	
	
	void add_character(char c){
		text[position] = c;
		remainder++;
		needSuffix = None;
		
		
		while(remainder > 0){
			// jesli punkt nie jest wewnatrz zadnej krawedzi, to teraz bedzie
			if(activeLen == 0){
				activeEdge = position;
			}
			
			// najprostszy przypadek: krawedzi z wierzcholka jeszcze nie ma;
			// wtedy ja po prostu tworzymy i nie myslimy
			int next = nodes[activeNode].nextNode[char_active_edge()];
			if(next == 0){
				int newNode = create_node(position, Infty);
				nodes[activeNode].nextNode[char_active_edge()] = newNode;
				
				process_suffix_link(activeNode);
			} else {
				// a gdy krawedz jest? sprobujmy wpierw przejsc cala krawedzia
				
				if(activeLen >= nodes[next].size(position)){
					// udalo sie!
					activeLen -= nodes[next].size(position);
					activeEdge += nodes[next].size(position);
					activeNode = next;
					continue; // i potem zaczynamy od poczatku
				}
				
				// nie udalo sie? a moze wszystko pasuje i nic nie trzeba robic?
				if(text[nodes[next].start + activeLen] == c){
					// wystarczy tylko powiekszyc aktywna dlugosc
					activeLen++;
					process_suffix_link(activeNode); // to robimy *zawsze*
					break; // juz skonczylismy
				}
				
				//printf("activeNode=%d\n", activeNode);
				// no to jednak nie pasuje; musimy zrobic splita
				int splitNode = create_node(nodes[next].start, nodes[next].start+activeLen);
				int leafNode = create_node(position, Infty);
				
				// laczymy pozostale ze splitNode
				nodes[activeNode].nextNode[char_active_edge()] = splitNode;
				nodes[next].start += activeLen;
				
				// laczymy splitNode z pozostalymi
				nodes[splitNode].nextNode[c] = leafNode;
				nodes[splitNode].nextNode[text[nodes[next].start]] = next;
				
				// no i oczywiscie suffix link
				process_suffix_link(splitNode);
			}
			
			remainder--; // wlasnie sie udalo dorzucic kolejny sufiks
			
			// przesuwamy aktywny punkt:
			// jesli byl rootem, to przenosimy o 1 wzgledem tekstu
			if(activeNode == Root && activeLen > 0){
				activeLen--;
				activeEdge = position - remainder + 1;
			} else {
				// inaczej albo zgodnie z suffix linkiem, albo do roota
				if(nodes[activeNode].suffixLink != None)
					activeNode = nodes[activeNode].suffixLink;
				else
					activeNode = Root;
			}
		}
		
		position++;
	}
};


/*****/




const int MaxLen = 300005;


char s1[MaxLen], s2[MaxLen], s3[MaxLen];
int len1, len2, len3, mlen;


void input(){
	scanf("%s%s%s", s1, s2, s3);
	len1 = strlen(s1);
	len2 = strlen(s2);
	len3 = strlen(s3);
	mlen = min(len1, min(len2,len3));
}

LL res[MaxLen];


void proc(bool p1, bool p2, bool p3, bool tadd){
	UkkonenTree UT(MaxLen);
	
	if(p1){
		for(int i = 0; i < len1; i++) UT.add_character(s1[i]);
		UT.add_character('$');
	}
	if(p2){
		for(int i = 0; i < len2; i++) UT.add_character(s2[i]);
		UT.add_character('$'-1);
	}
	if(p3){
		for(int i = 0; i < len3; i++) UT.add_character(s3[i]);
		UT.add_character('$'-2);
	}
	
	vector<LL> innRes;
	innRes.resize(MaxLen);
	UT.dfs_tree(0, 0, innRes);
	
	LL sum = 0;
	for(int i = 0; i <= mlen; i++){
		sum += innRes[i];
		if(tadd) res[i] += sum; else res[i] -= sum;
	}
}



int main(){
	input();
	proc(true, true, true, true);
	//printf("A\n");
	proc(true, true, false, false);
	proc(true, false, true, false);
	proc(false, true, true, false);
	proc(true, false, false, true);
	proc(false, true, false, true);
	proc(false, false, true, true);
	
	
	for(int i = 1; i <= mlen; i++)
		printf("%d ", res[i] % 1000000007);
	printf("\n");
	
	return 0;
}