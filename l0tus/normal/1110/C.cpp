#include <bits/stdc++.h>
using namespace std;
#define va first
#define vb second
typedef long long ll;
typedef pair<int,int> pii;
using namespace std;
const int MN = 1e6+5;
const int INF = 1e9;

int A[MN],B[MN],N,M,K,cnt,tmp,ans,val,Q;
string S;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    //freopen("C:\\Users\\user\\Desktop\\input.txt","r",stdin);
    cin >> Q;
    for(int i=0; i<Q; i++){
        cin >> N;
        cnt = 0;
        bool check = false;
        tmp = N;
        while(tmp){
            if(tmp%2==0) check = true;
            tmp/=2;
            cnt++;
        }
        if(check){
            cout << (1<<cnt)-1 << '\n';
            continue;
        }
        for(int i=2; i*i<=N; i++){
            if(N%i==0){
                cout << N/i << '\n';
                check = true;
                break;
            }
        }
        if(!check) cout << 1 << '\n';
    }
}