#include <bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin>>a;
    while(a--){
        long long int b,c;
        cin>>b>>c;
        c--;
        while(c--){
            int max=0,min=9;
            bool hmm=false;
            for(long long i=17;i>=0;i--){
                long long int yay=(b%((long long int)pow(10,i+1)))/pow(10,i);
                if(yay!=0){
                    hmm=true;
                }
                if(yay>max and hmm==true){
                    max=yay;
                }
                if(yay<min and hmm==true){
                    min=yay;
                }
            }
            if(min==0 and hmm==true || b==0){
                break;
            }
            else{
                b=b+(min*max);
            }
        }
        cout<<b<<"\n";
    }
	return 0;
}