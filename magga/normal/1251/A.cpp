#include<bits/stdc++.h>
using namespace std;
int val(char c){
    return(int(c) - int('a'));
}
void solve()
{
    string s;cin>>s;
    long long int n=s.size();
    bool arr[26]{0};
    for(long long int i=0;i<n;i++){
        if(i==n-1){
            arr[val(s[n-1])]=true;
        }else if(s[i]==s[i+1]){
            i++;
        }else{
            arr[val(s[i])]=true;
        }
        
    }
    for(int i=0;i<26;i++){
        if(arr[i]){
            cout<<(char)(i+int('a'));
        }
    }
    cout<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
       	//cout<<"Yahan tak chala"<<endl;
    }   
}