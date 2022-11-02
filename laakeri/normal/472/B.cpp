#include <iostream>

using namespace std;

int lol[2001];

int main(){
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++) {
        int a;
        cin>>a;
        lol[a]++;
    }
    int ps=n;
    int v=0;
    int ed=1;
    for (int i=1;i<=2000;i++){
        if (lol[i]>0){
            int ks=ps/k;
            if (ps%k) ks++;
            ks+=ks-1;
            v+=ks*(i-ed);
            //cout<<ks<<" "<<(i-ed)<<endl;
            ps-=lol[i];
            ed=i;
        }
    }
    v+=ed-1;
    cout<<v<<endl;
}