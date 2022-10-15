// i am just doing this to lower my TLE bot virtual solve speed

#include <bits/stdc++.h>
using namespace std;
#define int long long
void eat(){
    int n;
    cin>>n;
    int freq[144]={};
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        freq[(s[0]-'a')*12+s[1]-'a']++;
    }
    int ans=0;
    for(int i=0;i<144;i++){
        for(int j=i+1;j<144;j++){
            if(i/12==j/12||i%12==j%12)ans+=freq[i]*freq[j];
        }
    }
    cout<<ans<<"\n";
}
signed main(){
    int t=1;
    cin>>t;
    while(t--)eat();
}