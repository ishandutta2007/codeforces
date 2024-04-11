#include <iostream>

using namespace std;

typedef long long ll;

ll st[1001];

int MOD=1000000007;

ll sum (int a,int b){
    if (a) {
        ll ret=st[b]-st[a-1];
        if (ret<0){
            ret+=MOD;
        }
        return ret;
    }
    return st[b];
}

int main(){
    int n;
    cin>>n;
    ll s=0;
    for (int i=0;i<n;i++){
        int a;
        cin>>a;
        a--;
        if (a==i){
            s+=2;
        }
        else{
            s+=sum(a,i-1)+2;
            //cout <<sum(a,i-1)<<" "<<a<<" "<<i-1<<endl;
        }
        s%=1000000007;
        st[i]=s;
    }
    cout <<s<<endl;
}