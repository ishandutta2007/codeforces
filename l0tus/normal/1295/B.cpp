#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 2e5+5;
int cnt,high,low,A[MN];
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int N,X;
        for(int i=0; i<MN; i++) A[i]=0;
        cin >> N >> X;
        string S;
        cin >> S;
        cnt = low = high = 0;
        for(int i=0; i<N; i++){
            if(S[i]=='0') cnt++;
            else cnt--;
            high = max(high,cnt);
            low = min(low,cnt);
            A[cnt+100000]++;
        }
        if(cnt==0){
            int ans=0;
            if(low<=X&&X<=high) cout << "-1\n";
            else{
                for(int i=low; i<=high; i++){
                    if(i==X) ans+=A[i+100000];
                }
                if(0==X) ans++;
                cout << ans << '\n';
            }
        }
        else{
            int ans=0;
            for(int i=low; i<=high; i++){
                if(abs(i-X)%cnt==0&&(i<=X&&cnt>0||i>=X&&cnt<0)) ans+=A[i+100000];
            }
            if(0==X) ans++;
            cout << ans << '\n';
        }
    }
}