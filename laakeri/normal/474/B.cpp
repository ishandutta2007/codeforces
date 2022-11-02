#include <iostream>

using namespace std;

int a[100001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if (i) a[i]+=a[i-1];
    }
    int q;
    cin>>q;
    for (int i=0;i<q;i++){
        int b;
        cin>>b;
        int mi=0;
        int ma=n-1;
        while(mi<=ma){
            int m=(mi+ma)/2;
            if (a[m]<b){
                mi=m+1;
            }
            else{
                ma=m-1;
            }
        }
        cout<<mi+1<<'\n';
    }
}