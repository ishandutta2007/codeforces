#include <bits/stdc++.h>
#define first va
#define second vb
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 100;
int Q,N,A[MN],tmp,cnt;
string S;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> Q;
    for(int i=0; i<Q; i++){
        cin >> N;
        fill(A,A+20,0);
        for(int j=0; j<N; j++){
            cin >> tmp;
            cnt = 0;
            while(tmp%2==0){
                tmp/=2;
                cnt++;
            }
            A[cnt]++;
        }
        for(int j=0; j<=10; j++){
            A[j+1] += A[j]/2;
        }
        if(A[11]) cout << "YES\n";
        else cout << "NO\n";
    }
}