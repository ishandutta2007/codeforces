#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MN = 2e5+5;
bool a,b,c;
int sum;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int N;
    string S;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> S;
        sum = a = b = c = 0;
        for(int j=0; j<S.size(); j++){
            if(!a&&S[j]=='0') a=1;
            else if((int)(S[j]-'0')%2==0) b=1;
            sum += (int)(S[j]-'0');
        }
        if(sum%3==0) c=1;
        if(a&&b&&c) cout << "red\n";
        else cout << "cyan\n";
    }
}