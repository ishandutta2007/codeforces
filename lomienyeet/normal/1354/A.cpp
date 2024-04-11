#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int N,a,b,c,d;
    cin>>N;
    for(long long int i=0;i<N;i++){
        cin>>a>>b>>c>>d;
        long long int counter=b;
        a-=b;
        if(a>0){
            if(d>=c){
                cout<<-1<<"\n";
                continue;
            }
            else{
                counter+=a/(c-d)*c;
                if(a%(c-d)!=0){
                    counter+=c;
                    a-=b;
                }
            }
            cout<<counter<<"\n";
        }
        else{
            cout<<b<<"\n";
        }
    }
    return 0;
}