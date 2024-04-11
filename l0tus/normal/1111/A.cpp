#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAX = 3e4;
const int INF = 1e9;
int N,A[MAX],cnt,sum,ans;
char B[5]={'a','e','i','o','u'};
bool s,t;
string S,T;
int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> S >> T;
    if(S.size()!=T.size()){
        cout << "No";
        return 0;
    }
    for(int i=0; i<S.size(); i++){
        s = false;
        t = false;
        for(int j=0; j<5; j++){
            if(S[i]==B[j]) s=true;
            if(T[i]==B[j]) t=true;
        }
        if(s!=t){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}