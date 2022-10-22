#include <iostream>
#include <vector>

using namespace std;

struct Node{
	int val, cnt;
	int left, right;
	Node(){
		cnt = 0;
		val = left = right = -1;
	}
	Node(int a, int b, int c){
		cnt = 0;
		val = a, left = b, right = c;
	}
};

int N;
int A[300005], P[300005];
vector<Node> tree;

int main(void)
{
	cin >> N;
	for(int i = 1; i <= N; i++) cin >> A[i];
	for(int i = 1; i <= N; i++) cin >> P[i];
	
	tree.push_back(Node());
	for(int i = 1; i <= N; i++){
		int v = 0;
		for(int j = 31; j >= 0; j--){
			if(P[i]&(1<<j)){
				if(tree[v].left == -1){
					tree.push_back(Node());
					tree[v].left = tree.size()-1;
				}
				v = tree[v].left;
			}
			else{
				if(tree[v].right == -1){
					tree.push_back(Node());
					tree[v].right = tree.size()-1;
				}
				v = tree[v].right;
			}
		}
		tree[v].val = P[i];
		tree[v].cnt++;
	}
	
	for(int i = 1; i <= N; i++){
		bool flag;
		int v = 0, last, dir;
		for(int j = 31; j >= 0; j--){
			
			if(tree[v].left != -1 && tree[v].right != -1){
				last = v;
				flag = true;
			}else flag = false;
			
			if(A[i]&(1<<j)){
				if(tree[v].left == -1){
					v = tree[v].right;
					if(flag) dir = 1;
				}
				else{
					v = tree[v].left;
					if(flag) dir = 0;
				}
			}
			else{
				if(tree[v].right == -1){
					v = tree[v].left;
					if(flag) dir = 0;
				}
				else{
					v = tree[v].right;
					if(flag) dir = 1;
				}
			}
		}
		cout << (tree[v].val ^ A[i]) << " ";
		tree[v].cnt--;
		if(tree[v].cnt <= 0){
			if(dir) tree[last].right = -1;
			else tree[last].left = -1;
		}
	}
	cout << endl;
	
	/*for(int i = 0; i < tree.size(); i++){
		cout << tree[i].left << " " << tree[i].right << " " << tree[i].val << endl;
	}
	*/
	
	
	return 0;
}