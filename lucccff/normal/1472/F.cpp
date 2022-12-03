#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

typedef long long LL;

pair <int,int> p[200010];

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int i,j,k,l,m,n,t,q,flag;
    cin>>t;
    while(t--) {
        cin>>n>>m;
        for(i=0;i<m;i++) {
            cin>>k>>l;
            p[i]=make_pair(l,k);
        }
        sort(p,p+m);
        q=0;
        flag=1;
        l=0;
        for(i=0;i<m-1;i++) {
            if (p[i].first==p[i+1].first) {
                if ((i&1)||(q!=0)) {
                    flag=0;
                    break;
                }
                if (l!=0) {
                    flag=0;
                    break;
                }
            }
            else if (p[i].first+1==p[i+1].first&&p[i].second!=p[i+1].second) {
                if (((i&1)==0)||(q+((p[i].first+p[i].second)&1)*2-1)!=0) {
                    flag=0;
                    break;
                }
                if (l!=1) {
                    flag=0;
                    break;
                }
            }
            else if (p[i].second==p[i+1].second) {
                k=p[i+1].first-p[i].first-1;
                if (k&1) {
                    if (l!=1) {
                        flag=0;
                        break;
                    }
                }
            }
            else {
                k=p[i+1].first-p[i].first-1;
                if (!(k&1)) {
                    if (l!=1) {
                        flag=0;
                        break;
                    }
                }
            }
            l^=1;
            /*if (p[i].first+2==p[i+1].first&&p[i].second==p[i+1].second) {
                if (((i&1)==0)||(q+((p[i].first+p[i].second)&1)*2-1)!=0) {
                    flag=0;
                    break;
                }
            }*/
            q+=((p[i].first+p[i].second)&1)*2-1;
        }
        q+=((p[m-1].first+p[m-1].second)&1)*2-1;
        if (m&1) {
            flag=0;
        }
        if (q) {
            flag=0;
        }
        if (flag) {
            cout<<"YES\n";
        }
        else {
            cout<<"NO\n";
        }
    }
    return 0;
}