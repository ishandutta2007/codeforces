#include <iostream>

using namespace std;

typedef long long ll;

ll dp[100005][2];

string lol (string s1){
    for (int i=s1.size()-2;i>=0;i--){
        if (s1[i]=='1'&&s1[i+1]=='1'){
            if (i>0){
                if (s1[i-1]=='0'){
                    s1[i-1]='1';
                    s1[i]='0';
                    s1[i+1]='0';
                    i=min((int)s1.size()-1, i+4);
                }
            }
            else{
                s1='1'+s1;
                s1[1]='0';
                s1[2]='0';
                i=min((int)s1.size()-1, 4);
            }
        }
    }
    return s1;
}

int main(){
    string s1;
    string s2;
    cin>>s1>>s2;
    s1=lol(s1);
    s2=lol(s2);
    //cout<<s1<<" "<<s2<<endl;
    int s=0;
    if (s2.size()>s1.size()){
        swap(s1,s2);
        s=1;
    }
    int d=s1.size()-s2.size();
    //cout<<s1<<" "<<s2<<endl;
    for (int i=0;i<s1.size();i++){
        int a1=s1[i]-'0';
        int a2=0;
        if (i-d>=0){
            a2=s2[i-d]-'0';
        }
        if (a1>a2){
            if (s) cout<<"<"<<endl;
            else cout<<">"<<endl;
            return 0;
        }
        if (a2>a1){
            if (s) cout<<">"<<endl;
            else cout<<"<"<<endl;
            return 0;
        }
    }
    cout<<"="<<endl;
}