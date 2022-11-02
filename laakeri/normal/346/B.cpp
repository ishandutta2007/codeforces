#include <iostream>

using namespace std;

string dp[102][102][102];//max: pituus, viimeinen i s1, viimeinen i s2, kohta josta virus alkaa

int ne[102][30][2];

int main(){
    string s1;
    string s2;
    string v;
    cin>>s1>>s2>>v;
    for (int a=0;a<2;a++){
        string s;
        if (a) s=s2;
        else s=s1;
        for (int i=0;i<s.size();i++){
            for (char c='A';c<='Z';c++){
                ne[i][c-'A'][a]=-1;
                for (int ii=i;ii<s.size();ii++){
                    if (s[ii]==c){
                        ne[i][c-'A'][a]=ii;
                        break;
                    }
                }
            }
        }
    }
    string ms="";
    for (int i=0;i<=s1.size();i++){
        for (int ii=0;ii<=s2.size();ii++){
            for (int iii=0;iii<=min(i, ii);iii++){
                if (dp[i][ii][iii].size()>ms.size()){
                    ms=dp[i][ii][iii];
                }
                if (i<s1.size()&&ii<s2.size()){
                    for (char c='A';c<='Z';c++){
                        int n1=ne[i][c-'A'][0];
                        int n2=ne[ii][c-'A'][1];
                        if (n1>-1&&n2>-1){
                            string nex=dp[i][ii][iii]+c;
                            int akk=nex.size();
                            for (int ak=0;ak<nex.size();ak++){
                                int f=0;
                                for (int j=0;j<min(v.size(), nex.size()-ak);j++){
                                    if (nex[ak+j]!=v[j]){
                                        f=1;
                                        break;
                                    }
                                }
                                if (!f){
                                    akk=ak;
                                    break;
                                }
                            }
                            if (akk+v.size()>nex.size()){
                                //cout<<akk<<" "<<nex<<endl;
                                if (dp[n1+1][n2+1][akk].size()<nex.size()){
                                    dp[n1+1][n2+1][akk]=nex;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (ms.size()>0){
        cout<<ms<<endl;
    }
    else{
        cout<<0<<endl;
    }
}