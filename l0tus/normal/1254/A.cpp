#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 1e5+5;
int T,R,C,N,cnt,val,ans,cur,num,S[105][105];
char A[105][105];
bool ch[2][MN];
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> T;
    while(T--){
        cnt = 0;
        cin >> R >> C >> N;
        for(int i=0; i<R; i++)
            for(int j=0; j<C; j++){
                cin >> A[i][j];
                if(A[i][j]=='R') cnt++;
            }
        val = cnt/N;
        cur = 0;
        num = 0;
        for(int i=0; i<R; i++){
            if(i%2) for(int j=C-1; j>=0; j--){
                S[i][j] = cur;
                if(A[i][j]!='R') continue;
                num++;
                if(cur<N-1&&(cur<cnt%N&&num==val+1||cur>=cnt%N&&num==val)) cur++,num=0;
            }
            else for(int j=0; j<C; j++){
                S[i][j] = cur;
                if(A[i][j]!='R') continue;
                num++;
                if(cur<N-1&&(cur<cnt%N&&num==val+1||cur>=cnt%N&&num==val)) cur++,num=0;
            }
        }
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if(S[i][j]<10) cout << S[i][j];
                else if(S[i][j]<36) cout << (char)('a'+S[i][j]-10);
                else cout << (char)('A'+S[i][j]-36);
            }
            cout << '\n';
        }
    }
}