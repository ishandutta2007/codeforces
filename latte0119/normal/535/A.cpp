#include<bits/stdc++.h>
using namespace std;
int main(){
    string s[]={"zero","one","two","three","four",
                "five","six","seven","eight","nine",
                "ten","eleven","twelve","thirteen","fourteen",
                "fifteen","sixteen","seventeen","eighteen","nineteen"};
    string t[]={"zero","ten","twenty","thirty","forty",
                "fifty","sixty","seventy","eighty","ninety"};

    int N;
    cin>>N;
    if(N<20)cout<<s[N]<<endl;
    else{
        cout<<t[N/10];
        if(N%10)cout<<"-"<<s[N%10];
        cout<<endl;
    }
    return 0;
}