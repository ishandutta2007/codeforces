#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(char str[]) 
{
    int l = 0; 
    int h = strlen(str) - 1; 
    while (h > l) { 
        if (str[l++] != str[h--]) { 
            return false; 
        } 
    } 
    return true; 
}
int isvalid(string str){
    int l = 0; 
    bool b = false;
    int h = str.size()-1; 
    while (h > l) { 
        if (str[l++] != str[h--]) { 
            if(!b){
                b=true;
            }else{
                return -1;
            } 
        } 
    } 
    if(!b){
        return 0;
    }else{
        return 1;
    }
}
void solve(){
    long long int n;cin>>n;
    long long int ans = 0;
    long long int vaaaalid = 0;
    long long int n0,n1;
    long long int nodd= 0;
    n0=0;n1=0;
    //long long int arr[n];
    string s;
    for(long long int i=0;i<n;i++){
        cin>>s;
        if(s.size()%2==1){
            nodd++;
        }
        for(long long int j=0;j<s.size();j++){
            if(s[j]=='1'){
                n1++;
            }else{
                n0++;
            }
        }
    }
    //cout<<n1<<" "<<n0<<endl;
    if(nodd>0 || (nodd==0 &&  (n0%2==0) &&  (n1%2==0))){
        cout<<n<<"\n";
    }else{
        cout<<n-1<<"\n";
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}