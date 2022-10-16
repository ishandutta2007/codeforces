#include<bits/stdc++.h>
using namespace std;
void solve()
{
    string s, t, p;
    bool flag = true; 
    map <char,int> req;
    map <char,int> avail;
    cin>>s>>t>>p;
    long long int j = 0;
    for(long long int i=0;i< s.size();i++){
        //cout<<s[i]<<" "<<i<<" "<<t[j]<<" "<<j<<endl;
        bool b = false;
        while(j<t.size()){
            if(s[i]==t[j]){
                b= true;
                //cout<<s[i]<<" "<<i<<" "<<t[j]<<" "<<j<<endl;
                j++;
                break;
            }else{
                req[t[j]]++;
                //cout<<req[t[j]]<<" "<<t[j]<<"\n";
                j++;
            }
        }
        if(!b){
            flag = false;
            cout<<"NO"<<"\n";
            return;
        }
        if(i==s.size()-1){
            while(j<t.size()){
                req[t[j]]++;
                j++;
            }
        }
    }
    for(long long int i=0;i<p.size();i++){
        avail[p[i]]++;
    }
    for(pair<char,int> p1: req){
        //cout<<p1.first<<" "<<avail[p1.first]<<" "<<p1.second<<"\n";
        if(avail[p1.first]<p1.second){
            flag = false;
            cout<<"NO"<<"\n";
            return;
        }
    }
    cout<<"YES"<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num;
    cin>>num;
    for(long long int i=0;i<num;i++)
    {
       	solve();
    }   
}