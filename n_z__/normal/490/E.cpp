#include <iostream>
typedef long long ll;
using namespace std;
 
string s[100005];
 
int judge(string s){
    int len = s.size();
    for(int i = 0;i < len;i ++)
        if(s[i] == '?')
            return 1;
    return 0;
}
 
int solve(int cur){
    if(cur == 1){
        for(int i = 0;i < s[cur].size();i ++){
            if(s[cur][i] == '?'){
                if(i == 0)  s[cur][i] = '1';
                else    s[cur][i] = '0';
            }
        }
        return 1;
    }
 
    if(s[cur].size() < s[cur-1].size())
        return 0;
 
    if(s[cur].size() > s[cur-1].size()){
        if(s[cur][0] == '?'){
            s[cur][0] = '1';
            for(int i = 1;i < s[cur].size();i ++)
                if(s[cur][i] == '?')
                    s[cur][i] = '0';
        }
        else{
            for(int i = 1;i < s[cur].size();i ++)
                if(s[cur][i] == '?')
                    s[cur][i] = '0';
        }
        return 1;
    }
 
    string temp = s[cur];
    for(int i = 0;i < temp.size();i ++)
        if(s[cur][i] == '?')
            temp[i] = s[cur-1][i];
 
    int flag = 0;
    int ok = 0;
    int equall = 0;
    for(int i = 0;i < temp.size();i ++){
        if(temp[i] != s[cur-1][i] && !equall){
            equall = 1;   
            if(temp[i] > s[cur-1][i]){    
                ok = 1;
                for(int j = i+1;j < temp.size();j ++)
                    if(s[cur][j] == '?')
                        temp[j] = '0';
                break;
            }
            else{     
                for(int j = i-1;j >= 0;j --){
                    if(s[cur][j] == '?' && temp[j] != '9'){
                        temp[j] = s[cur-1][j]+1;
                        for(int k = j+1;k < temp.size();k ++)
                            if(s[cur][k] == '?')
                                temp[k] = '0';
                        ok = 1;
                        break;
                    }
                }
                if(!ok)
                    return 0;
            }
            break;
        }
        if(equall)
            break;
    }
    if(!equall){        
        for(int i = temp.size()-1;i >= 0;i --){
            if(temp[i] != '9' && s[cur][i] == '?'){
                temp[i] = s[cur-1][i]+1;
                for(int j = i+1;j < temp.size();j ++)
                    if(s[cur][j] == '?')
                        temp[j] = '0';
                ok = 1;
                break;
            }
        }
    }
    if(!ok) return 0;
    else
        s[cur] = temp;
    return 1;
}
 
int judge2(int cur){
    if(cur == 1)    return 1;
 
    if(s[cur].size() < s[cur-1].size())   return 0;
    if(s[cur].size() > s[cur-1].size())   return 1;
 
    else{
        for(int i = 0;i < s[cur].size();i ++)
            if(s[cur][i] < s[cur-1][i])
                return 0;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    while(cin>>n){
        for(int i = 1;i <= n;i ++)  cin>>s[i];
 
        ll res = 0;
        int ok = 1;
        for(int i = 1;i <= n;i ++){
                if(!solve(i)){
                    ok = 0;
                    break;
                }
        }
        if(!ok) cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            for(int i = 1;i <= n;i ++)
                cout<<s[i]<<endl;
        }
    }
    return 0;
}