#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
char n[15],m[15];//10^9
int ln,lm;//nm
bool cmp(char a,char b){
    return a<b;
}//ASCII
int main(){
    cin>>n>>m;
    ln=strlen(n);
    lm=strlen(m);
    //1
    if(ln!=lm){
        printf("WRONG_ANSWER");
        return 0;
    }
    //20
    else if(n[0]=='0'&&m[0]=='0'){
        printf("OK");
        return 0;
    }
    sort(n,n+ln,cmp);
    int i=0;//0
    while(n[i]=='0'){
        i++;
    }//n[i]0
    swap(n[0],n[i]);//
    if(strcmp(n,m)==0)//<cstring>
        printf("OK");
    else
        printf("WRONG_ANSWER");
    return 0;
}