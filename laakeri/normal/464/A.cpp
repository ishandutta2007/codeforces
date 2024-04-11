#include <iostream>

using namespace std;

int n,p;

string test(int x, char c, string s){
    //cout<<x<<" "<<c<<" "<<s<<endl;
    char mc='a'+(p-1);
    s[x]=c;
    for (int i=x+1;i<n;i++){
        s[i]='a';
    }
    for (int i=2;i<n;i++){
        if (i<=x){
            if (s[i]==s[i-1]||s[i]==s[i-2]||s[i-1]==s[i-2]){
                return "";
            }
        }
        else{
            if (s[i-1]==s[i-2]){
                return "";
            }
            while (s[i]==s[i-1]||s[i]==s[i-2]){
                s[i]++;
                if (s[i]>mc){
                    return "";
                }
            }
        }
    }
    return s;
}

int main(){
    cin>>n>>p;
    string s;
    cin>>s;
    char mc='a'+(p-1);
    if (n==2){
        if (s[1]<mc){
            s[1]++;
        }
        else{
            s[0]++;
            s[1]='a';
        }
        if (s[0]==s[1]){
            s[1]++;
            if (s[1]>mc){
                cout<<"NO"<<endl;
                return 0;
            }
        }
        cout<<s<<endl;
        return 0;
    }
    if (n==1){
        s[0]++;
        if (s[0]>mc) cout<<"NO"<<endl;
        else cout<<s<<endl;
        return 0;
    }
    for (int i=n-1;i>=0;i--){
        for (char c=s[i]+1;c<'a'+p;c++){
            string ss=test(i, c, s);
            if (ss!=""){
                cout<<ss<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;
}