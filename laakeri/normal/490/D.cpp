#include <iostream>

using namespace std;

typedef long long ll;

int main(){
    ll a1,b1,a2,b2;
    cin>>a1>>b1>>a2>>b2;
    ll asd1=a1*b1;
    ll asd2=a2*b2;
    ll n1=1;
    ll n2=1;
    int n12s=0;
    int n13s=0;
    int n22s=0;
    int n23s=0;
    while (asd1%2ll==0ll){
        asd1/=2ll;
        n1*=2ll;
        n12s++;
    }
    while (asd1%3ll==0ll){
        asd1/=3ll;
        n1*=3ll;
        n13s++;
    }
    while (asd2%2ll==0ll){
        asd2/=2ll;
        n2*=2ll;
        n22s++;
    }
    while (asd2%3ll==0ll){
        asd2/=3ll;
        n2*=3ll;
        n23s++;
    }
    if (asd1!=asd2){
        cout<<-1<<endl;
        return 0;
    }
    int v=0;
    while (n12s+n13s>n22s+n23s){
        if (n12s>n22s){
            n12s--;
            n1/=2ll;
            if (a1%2ll==0){
                a1/=2ll;
            }
            else{
                b1/=2ll;
            }
            v++;
        }
        else if (n13s>n23s){
            n13s--;
            n1/=3ll;
            if (a1%3ll==0){
                a1/=3ll;
            }
            else{
                b1/=3ll;
            }
            v+=2;
        }
    }
    while (n12s+n13s<n22s+n23s){
        if (n22s>n12s){
            n22s--;
            n2/=2ll;
            if (a2%2ll==0){
                a2/=2ll;
            }
            else{
                b2/=2ll;
            }
            v++;
        }
        else if (n23s>n13s){
            n23s--;
            n2/=3ll;
            if (a2%3ll==0){
                a2/=3ll;
            }
            else{
                b2/=3ll;
            }
            v+=2;
        }
    }
    while (n13s>n23s){
        n13s--;
        n1/=3ll;
        n1*=2ll;
        if (a1%3ll==0){
            a1/=3ll;
            a1*=2ll;
        }
        else{
            b1/=3ll;
            b1*=2ll;
        }
        v++;
    }
    while (n23s>n13s){
        n23s--;
        n2/=3ll;
        n2*=2ll;
        if (a2%3ll==0){
            a2/=3ll;
            a2*=2ll;
        }
        else {
            b2/=3ll;
            b2*=2ll;
        }
        v++;
    }
    cout<<v<<endl;
    n1*=asd1;
    n2*=asd2;
    cout<<a1<<" "<<b1<<endl;
    cout<<a2<<" "<<b2<<endl;
}