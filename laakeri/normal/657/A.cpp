#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

void nie(){
    cout<<"-1"<<endl;
    exit(0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,d,h;
    cin>>n>>d>>h;
    if (h==1){
        if (d==1){
            if (n==2){
                cout<<"1 2"<<endl;
                return 0;
            }
            else{
                nie();
            }
        }
        else if(d==2){
            for (int i=2;i<=n;i++){
                cout<<"1 "<<i<<'\n';
            }
            return 0;
        }
        else{
            nie();
        }
    }
    if (h*2<d) nie();
    for (int i=2;i<=h+1;i++){
        cout<<i-1<<" "<<i<<'\n';
    }
    int f=0;
    for (int i=h+2;i<=d+1;i++){
        f=1;
        if (i==h+2){
            cout<<"1 "<<i<<'\n';
        }
        else{
            cout<<i-1<<" "<<i<<'\n';
        }
    }
    for (int i=d+2;i<=n;i++){
        if (f){
            cout<<"1 "<<i<<'\n';
        }
        else{
            cout<<"2 "<<i<<'\n';
        }
    }
}