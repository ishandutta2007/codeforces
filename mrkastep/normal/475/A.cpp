#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

#define For(i,n) for(i=0;i<(n);i++)
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define pb push_back
#define ll long long

int n;

bool read(){
    if(scanf("%d",&n)!=1) return false;
    return true;
}

void solve(){
    char i,m[40];
    For(i,40) m[i]='#';
    For(i,n) m[i]='O';
    printf("+------------------------+\n");
    printf("|%c.%c.%c.%c.%c.%c.%c.%c.%c.%c.%c.|D|)\n",m[0],m[4],m[7],m[10],m[13],m[16],m[19],m[22],m[25],m[28],m[31]);
    printf("|%c.%c.%c.%c.%c.%c.%c.%c.%c.%c.%c.|.|\n",m[1],m[5],m[8],m[11],m[14],m[17],m[20],m[23],m[26],m[29],m[32]);
    printf("|%c.......................|\n",m[2]);
    printf("|%c.%c.%c.%c.%c.%c.%c.%c.%c.%c.%c.|.|)\n",m[3],m[6],m[9],m[12],m[15],m[18],m[21],m[24],m[27],m[30],m[33]);
    printf("+------------------------+");
}


int main() {
#pragma comment(linker, "/STACK:268435456")
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int i;
    while(read()){
        solve();
    }
    return 0;

}