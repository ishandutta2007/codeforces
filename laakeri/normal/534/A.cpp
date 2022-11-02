#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    if (n<3){
        cout<<1<<endl<<1<<endl;
    }
    if (n==3){
        cout<<2<<endl<<"1 3"<<endl;
    }
    if (n==4){
        cout<<4<<endl<<"2 4 1 3"<<endl;
    }
    if (n>4){
        cout<<n<<endl;
        for (int i=1;i<=n;i+=2){
            cout<<i<<" ";
        }
        for (int i=2;i<=n;i+=2){
            cout<<i<<" ";
        }
    }
}