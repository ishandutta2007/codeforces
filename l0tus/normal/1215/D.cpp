#include <bits/stdc++.h>
using namespace std;
#define first va
#define second vb
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 2e5+5;
int N,A[MN],B[MN],cnt1,cnt2,sum1,sum2;
string S;
int main()
{
    cin >> N >> S;
    for(int i=0; i<N; i++){
        A[i] = S[i]-'0';
        if(i<N/2){
            if(S[i]=='?') cnt1++;
            else sum1 += S[i]-'0';
        }
        else{
            if(S[i]=='?') cnt2++;
            else sum2 += S[i]-'0';
        }
        if(cnt1>=2){
            sum1 += 9, cnt1 -= 2;
        }
        if(cnt2>=2){
            sum2 += 9, cnt2 -= 2;
        }
    }
    if(sum1==sum2) cout << "Bicarp";
    else cout << "Monocarp";
}