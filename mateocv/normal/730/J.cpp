#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;i++)
#define FIN ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define SZ(a) ((int)(a).size())
#define ALL(a) a.begin(),a.end()
#define fst first
#define snd second

ll pre[110][10010];
ll now[110][10010];



int main() {FIN;
	int n; cin>>n;
	vector<ii> a(n);
	ll tot=0,all=0;
	fore(i,0,n) cin>>a[i].snd, tot+=a[i].snd;
	fore(i,0,n) cin>>a[i].fst,all+=a[i].fst;
	sort(ALL(a)); reverse(ALL(a));
	ll ac=0,need=0;
	fore(i,0,n){
		ac+=a[i].fst;
		need++;
		if(ac>=tot) break;
	}
	fore(i,0,n+1) fore(j,0,all+1) pre[i][j]=1e9;
	fore(j,tot,all+1) pre[0][j]=0;
	
	fore(i,0,n){
		fore(j,0,n+1){
			fore(k,0,all+1){
				now[j][k]=pre[j][k];
				if(j&&a[i].fst<=k){
					ll xx=pre[j-1][k-a[i].fst] + a[i].snd;
					now[j][k] = min(now[j][k], xx);
				}
			}
		}
		swap(pre,now);
	}
	cout << need << " ";
	ll ans=pre[n-need][all];
	cout << ans<< "\n";
}