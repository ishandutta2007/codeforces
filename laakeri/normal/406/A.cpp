#include <iostream>

using namespace std;

int ebin[1001];

int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    int s=0;
    for (int i=0;i<n;i++){
        for (int ii=0;ii<n;ii++){
            int a;
            cin>>a;
            if (i==ii){
                ebin[i]=a;
                s+=a;
            }
        }
    }
    int q;
    cin>>q;
    string st;
    for (int i=0;i<q;i++){
        int a,b;
        cin>>a;
        if (a==3){
            st+=(char)(s%2+'0');
        }
        if (a==2||a==1){
            cin>>b;
            b--;
            if (ebin[b]){
                ebin[b]=0;
                s--;
            }
            else{
                ebin[b]=1;
                s++;
            }
        }
    }
    cout <<st<<endl;
}