#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    map<int,bool> mp;
    int pos=0,maxi=0;
    while(T--){
        int N;
        char bruh;
        cin>>bruh>>N;
        if(bruh=='+'){
            pos++;
            mp[N]=true;
            maxi=max(maxi,pos);
        }
        else{
            if(mp[N]==true){
                mp[N]=false;
                pos--;
            }
            else maxi++;
        }
    }
    cout<<maxi<<"\n";
    return 0;
}