#include <bits/stdc++.h>
using namespace std;
int n,x,fuck,maxi,a[734727];
void shit(int on9){
    for(int i=0;on9;i++){
        int tp=min(on9,9-a[i]);
        on9-=tp;
        a[i]+=tp;
        maxi=max(maxi,i);
    }
}
int main(){
    int n;
    cin>>n;
    while(n--){
        cin>>x;
        if(x>fuck)shit(x-fuck);
        else{
            fuck=x-fuck;
            for(int ptr=0;true;ptr++){
                maxi=max(maxi,ptr);
                if(a[ptr]<9&&fuck>0){
                    a[ptr]++;
                    shit(fuck-1);
                    break;
                }
                else{
                    fuck+=a[ptr];
                    a[ptr]=0;
                }
            }
        }
        for(int i=maxi;i>=0;i--)cout<<a[i];
        cout<<"\n";
        fuck=x;
    }
}