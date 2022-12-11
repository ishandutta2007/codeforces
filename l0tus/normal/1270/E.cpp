#include <bits/stdc++.h>
#define va firsst
#define vb second
using namespace std;
typedef long long ll;
const ll INF = 2e9;
const int MN = 1005;
ll N,cnt,val=2,X[MN],Y[MN],ch[MN];
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++) cin >> X[i] >> Y[i];
    cnt = 0;
    while(cnt==0||cnt==N){
        cnt = 0;
        for(int i=0; i<N; i++){
            ch[i] = (X[i]+Y[i]+INF)%val;
            if(ch[i]<val/2) cnt++;
        }
        if(cnt==0||cnt==N){
            cnt = 0;
            for(int i=0; i<N; i++){
                ch[i] = (X[i]+INF)%val;
                if(ch[i]<val/2) cnt++;
            }
        }
        val *= 2;
    }
    cout << cnt << '\n';
    for(int i=0; i<N; i++) if(ch[i]<val/4) cout << i+1 << ' ';
}