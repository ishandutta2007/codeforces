#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<cassert>
using namespace std;
#define ran 101111
#define i64 long long int
#define u64 long double
int a[ran],b[ran];
vector<int> e[ran];
i64 d[ran];
int L[ran],R[ran],tim,_L[ran];
void dfs(int x,int fat){
	_L[++tim] = x;
	L[x] = tim;
	for(vector<int>::iterator it = e[x].begin(); it != e[x].end(); it++){
		int y = *it;
		if(y == fat)continue;
		dfs(y, x);
	}
	R[x] = tim;
}

vector<int> seg[ran * 4];
int ready[ran * 4], ready1[ran];
int ss[ran * 4], ee[ran * 4];
int pos[ran];
int q[ran * 5],op,cl;
void build(int i,int s,int e){
	ss[i] = s;
	ee[i] = e;
	if(s == e){
		ready[i] = 1;
		pos[s] = i;
		return;
	}
	ready[i] = 2;
	int m=(s+e)/2;
	build(i*2,s,m);
	build(i*2+1,m+1,e);
}
void proc(int i,int s,int e,int l,int r,int x){
	if(s==l && e==r){
		seg[i].push_back(x);
		ready1[x] ++;
		return;
	}
	int m=(s+e)/2;
	if(r<=m)proc(i*2,s,m,l,r,x);else
		if(l>m)proc(i*2+1,m+1,e,l,r,x);else{
			proc(i*2,s,m,l,m,x);
			proc(i*2+1,m+1,e,m+1,r,x);
		}
}



struct KX_B{

int pnt;
vector<long long int> M,B;
void init(){
	pnt = 0;
	M.clear();
	B.clear();
}
bool bad(int l1,int l2,int l3){
	return (((u64)(B[l3]-B[l1]))*((u64)(M[l1]-M[l2]))) < (((u64)(B[l2]-B[l1]))*((u64)(M[l1]-M[l3])));
}
void add(long long int m,long long int b){

	if(M.size() != 0 && m == M.back() && b <= B.back())return;

	M.push_back(m);
	B.push_back(b);
	while (M.size()>=3&&bad(M.size()-3,M.size()-2,M.size()-1)){
		M.erase(M.end()-2);
		B.erase(B.end()-2);
	}
	if(pnt >= M.size())pnt = M.size() - 1;
}
long long int query(long long int x){
	while (pnt < M.size() - 1 &&
		M[pnt+1]*x+B[pnt+1] >= M[pnt]*x+B[pnt])pnt++;
	return M[pnt]*x+B[pnt];
}

} kxb;

i64 dp[ran];
void upd(int x,i64 val){
	if(dp[x] > val)dp[x] = val;
}
void upd1(int s,int e,vector<int> query_id){
	if(query_id.empty())return;
	kxb.init();
	vector<pair<int,i64> > vv;
	for(int i=s; i<=e; i++){
		assert(dp[_L[i]] < 1e17);
		vv.push_back(make_pair(-b[_L[i]], -dp[_L[i]]));
	}
	sort(vv.begin(), vv.end());
	for(vector<pair<int,i64> >::iterator it = vv.begin(); it != vv.end(); it++)
		kxb.add(it->first, it->second);
	vector<pair<int,int> > vv2;
	for(vector<int>::iterator it=query_id.begin(); it != query_id.end(); it++){
		vv2.push_back(make_pair(a[*it], *it));
	}
	sort(vv2.begin(), vv2.end());
	for(vector<pair<int,int> >::iterator it = vv2.begin(); it != vv2.end(); it++){
		upd(it->second, -kxb.query(it->first));
	}
}

int n;
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	for(int i=1; i<=n; i++)
		scanf("%d",&b[i]);
	for(int i=1; i<n; i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1,1);
	build(1, 1, n);
	op=cl=0;
	for(int i=1; i<=n; i++)if(L[i] == R[i]){
		dp[i] = 0;
		q[op++] = -i;
	}else{
		dp[i] = (i64)1e18;
		proc(1,1,n,L[i]+1,R[i],i);
	}
	while(cl<op){
		int z = q[cl++];
		if(z < 0){
			z = -z;
			int ii = pos[L[z]];
			if(--ready[ii] == 0)
				q[op++] = ii;
		}else{
			int ii = z / 2;
			if(--ready[ii] == 0)
				q[op++] = ii;
			for(vector<int>::iterator it = seg[z].begin(); it != seg[z].end(); it++){
				int id = *it;
				if(--ready1[id] == 0){
					q[op++] = -id;
				}
			}
			upd1(ss[z], ee[z], seg[z]);
		}
	}
	for(int i=1; i<=n; i++)
		printf("%I64d%c",dp[i], i<n?' ':'\n');
	return 0;
}