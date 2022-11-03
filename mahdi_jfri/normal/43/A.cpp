#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    int n,b=0,s=0,x;
    cin>>n;
    int cop=n;
    string a[n];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    b++;
    n=0;
    int i=1;
    while(s+b<cop){
        if (a[n]==a[i]){
            b++;
        }
        if (a[n]!=a[i]){
            s++;
            x=i;
        }
        i++;
        }
        i=0;
        if (b>s){
            cout<<a[i];
        }
        if(b<s){
            cout<<a[x];
        }
    return 0;
}