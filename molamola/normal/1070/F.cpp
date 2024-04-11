#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define repp(i,n) for(int i=1;i<=n;i++)

int n, M;
#define N_ 401000

long long S, S1[N_], S2[N_], res;
vector<int>V[3];

int main(){
	int i, a, b;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&a,&b);
		if(a==11)S+=b, M++;
		else if(a==0)V[0].push_back(b);
		else if(a==1)V[1].push_back(b);
		else V[2].push_back(b);
	}
	sort(V[0].begin(),V[0].end());
	sort(V[1].begin(),V[1].end());
	sort(V[2].begin(),V[2].end());
	for(i=1;i<=V[1].size();i++){
		S1[i] = S1[i-1] + V[1][V[1].size()-i];
	}
	for(i=1;i<=V[2].size();i++){
		S2[i] = S2[i-1] + V[2][V[2].size()-i];
	}
	int pv = 0;
	int sz1 = V[1].size(), sz2 = V[2].size();
	long long t = 0;
	res = S;
	for(i=0;i<=V[0].size() && i<=M;i++){
		if(abs(sz1 - sz2) <= M-i){
			res = max(res, S + t + S1[sz1] + S2[sz2]);
		}
		else{
			if(sz1 > sz2){
				res = max(res, S + t + S1[sz2 + M-i] + S2[sz2]);
			}
			else{
				res = max(res, S + t + S2[sz1 + M-i] + S1[sz1]);
			}
		}
		if(i==V[0].size())break;
		t += V[0][V[0].size()-i-1];
	}
	printf("%lld\n",res);
}