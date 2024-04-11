#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
#define pli pair<long long,int>

#define Fi first
#define Se second
#define N_ 201000

int n, m, CA, CB, Last[N_];

int A[N_], B[N_];
set<int>S1,S2;
vector<pii>Ans;

void Add_Edge(int a, int b){
	Ans.push_back({a,b});
}

int main() {
	int i;
	scanf("%d%d%d%d",&n,&m,&CA,&CB);
	for(i=1;i<=CA;i++){
		scanf("%d",&A[i]);
		Last[A[i]] = i;
	}
	for(i=1;i<=CB;i++){
		scanf("%d",&B[i]);
		Last[B[i]] = i;
	}
	for(i=1;i<=n;i++)if(!Last[i])S1.insert(i);
	for(i=n+1;i<=n+m;i++)if(!Last[i])S2.insert(i);
	int p1 = 1, p2 = 1;
	while(p1<=CA || p2 <= CB){
		if(p2<=CB && !S1.empty()){
			int t = *S1.begin();
			Add_Edge(B[p2], t);
			S1.erase(S1.begin());
			if(Last[B[p2]] == p2){
				S2.insert(B[p2]);
			}
			p2++;
		}
		else if(p1<=CA && !S2.empty()){
			int t = *S2.begin();
			Add_Edge(A[p1], t);
			S2.erase(S2.begin());
			if(Last[A[p1]]==p1){
				S1.insert(A[p1]);
			}
			p1++;
		}
		else{
			puts("No");
			return 0;
		}
	}
	if(S1.empty()||S2.empty()){
		puts("No");
		return 0;
	}
	for(auto &t : S2){
		Add_Edge(*S1.begin(),t);
	}
	for(auto &t : S1){
		if(t==*S1.begin())continue;
		Add_Edge(*S2.begin(),t);
	}
	puts("Yes");
	for(auto &t : Ans){
		printf("%d %d\n",t.first,t.second);
	}
}