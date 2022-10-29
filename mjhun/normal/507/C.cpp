#include <iostream>
using namespace std;

int main(){

int h,k=0; long long n,r=0;
cin>>h>>n;n--;
while(h--){
    if(((n>>h)&1)!=k)
        r+=1LL<<(h+1);
    else {
        r++;
        k^=1;
    }
}
cout<<r<<endl;

}