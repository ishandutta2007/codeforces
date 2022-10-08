#include <bits/stdc++.h>

#define pb push_back
#define f first
#define s second
#define mp make_pair
#define pq priority_queue

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll=pair<ll,ll>;
using vi = vector<int>;
using vivi=vector<vi>;
using vb=vector<bool>;
using vll=vector<ll>;
using vpii=vector<pii>;
using str = string;

const ll inf = 2 * 1e18;

int main() {


    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vi a(n);
    for (int i=0;i<n;++i) cin>>a[i];

    vi x;
    vi y;
    x.pb(a[0]);
    for (int i=1;i<n;++i){
        if (a[i]>a[i-1]){
            x.pb(a[i]);
        }
        else break;
    }
    y.pb(a[n-1]);
    for (int i=n-2;i>=0;--i){
        if (a[i]>a[i+1]){
            y.pb(a[i]);
        }
        else break;
    }

    int i=0;
    int j=0;
    int turn=0;
    int prev=-1;
    while (true){
//        cout<<i<<" "<<j<<endl;
        if (i==x.size()){
            int left=0;
            if (y[j]>prev){
                left=y.size()-j;
            }
            turn=(turn+left)%2;
            if (turn%2==0){
                cout<<"Bob"<<endl;
                return 0;
            }
            else{
                cout<<"Alice"<<endl;return 0;
            }
        }
        else if (j==y.size()){
            int left=0;
            if (x[i]>prev){
                left=x.size()-i;
            }
            turn=(turn+left)%2;
            if (turn%2==0){
                cout<<"Bob"<<endl;return 0;
            }
            else{
                cout<<"Alice"<<endl;return 0;
            }
        }
        else{
            if (x[i]>prev && y[j]<=prev){
                prev=x[i];++i;++turn;
            }
            else if (y[j]>prev && x[i]<=prev){
                prev=y[j];++j;++turn;
            }
            else{
                if (y[j]>x[i]){
                    int left=y.size()-j;
                    if (left%2==0){
                        prev=x[i];++i;++turn;
                    }
                    else{
                        prev=y[j];++j;++turn;
                    }
                }
                else if (x[i]>y[j]){
                    int left=x.size()-i;
                    if (left%2==1){
                        prev=x[i];++i;++turn;
                    }
                    else{
                        prev=y[j];++j;++turn;
                    }
                }
                else{
                    int left1=x.size()-i;
                    int left2=y.size()-j;
                    if (left1%2==1){
                        prev=x[i];++i;++turn;
                    }
                    else{
                        prev=y[j];++j;++turn;
                    }
                }
            }
        }
    }

    return 0;
}