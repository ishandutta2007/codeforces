#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n;
string s,a1,a2;
string add(string a,string b){
    string cc;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    if(a.size()<b.size())swap(a,b);
    int top=0,sum;
    for(int i=0;i<b.size();i++){
        sum=(b[i]-'0'+a[i]-'0'+top);
        top=(sum>=10)?1:0;
        if(sum>=10)sum-=10;
        cc.push_back(sum+'0');
    }
    for(int i=b.size();i<a.size();i++){
        sum=a[i]-'0'+top;
        top=(sum>=10)?1:0;
        if(sum>=10)sum-=10;
        cc.push_back(sum+'0');
    }
    if(top) cc.push_back('1');
    reverse(cc.begin(),cc.end());
    return cc;
}
string mini(string a,string b){
    if(a.empty()||b.empty())
        return a.empty()?b:a;
    if(a.size()!=b.size()){
        return a.size()<b.size()?a:b;
    }
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i])
            return a[i]<b[i]?a:b;
    }
    return a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>s;
    int t=n/2;
    //cout<<add("2","3")<<endl;
    for(int i=t+1;i<n;i++){
        if(s[i]>'0'){
            string aa,bb;
            for(int j=0;j<i;j++)
                aa.push_back(s[j]);
            for(int j=i;j<n;j++)
                bb.push_back(s[j]);
                a1=add(aa,bb);
            break;
        }
    }
    for(int i=t;i>=0;i--){
        if(s[i]>'0'){
            string aa,bb;
            for(int j=0;j<i;j++)
                aa.push_back(s[j]);
            for(int j=i;j<n;j++)
                bb.push_back(s[j]);
            a2=add(aa,bb);
            break;
        }
    }
   // cout<<a1<<' '<<a2<<'\n';
   // cout<<a1<<' '<<a2<<endl;
    cout<<mini(a1,a2);
}