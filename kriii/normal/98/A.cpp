#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

string C;

map<string,bool> IN;
int CNT,CHK[6];

void go(int v, string m)
{
    int i;
    if (v == 6){
        string t; char temp;
        t = m;
        for (i=0;i<4;i++){
            temp = t[1]; t[1] = t[2]; t[2] = t[3]; t[3] = t[4]; t[4] = temp;
            if (IN.count(t)) return;
        }

        t = m;
        temp = t[0]; t[0] = t[5]; t[5] = temp;
        temp = t[2]; t[4] = t[4]; t[2] = temp;
        for (i=0;i<4;i++){
            temp = t[1]; t[1] = t[2]; t[2] = t[3]; t[3] = t[4]; t[4] = temp;
            if (IN.count(t)) return;
        }

        t = m;
        temp = t[0]; t[0] = t[1]; t[1] = t[5]; t[5] = t[3]; t[3] = temp;
        for (i=0;i<4;i++){
            temp = t[1]; t[1] = t[2]; t[2] = t[3]; t[3] = t[4]; t[4] = temp;
            if (IN.count(t)) return;
        }

        t = m;
        temp = t[0]; t[0] = t[1]; t[1] = t[5]; t[5] = t[3]; t[3] = temp;
        temp = t[0]; t[0] = t[5]; t[5] = temp;
        temp = t[2]; t[4] = t[4]; t[2] = temp;
        for (i=0;i<4;i++){
            temp = t[1]; t[1] = t[2]; t[2] = t[3]; t[3] = t[4]; t[4] = temp;
            if (IN.count(t)) return;
        }

        t = m;
        temp = t[0]; t[0] = t[2]; t[2] = t[5]; t[5] = t[4]; t[4] = temp;
        for (i=0;i<4;i++){
            temp = t[1]; t[1] = t[2]; t[2] = t[3]; t[3] = t[4]; t[4] = temp;
            if (IN.count(t)) return;
        }

        t = m;
        temp = t[0]; t[0] = t[2]; t[2] = t[5]; t[5] = t[4]; t[4] = temp;
        temp = t[0]; t[0] = t[5]; t[5] = temp;
        temp = t[2]; t[4] = t[4]; t[2] = temp;
        for (i=0;i<4;i++){
            temp = t[1]; t[1] = t[2]; t[2] = t[3]; t[3] = t[4]; t[4] = temp;
            if (IN.count(t)) return;
        }

        CNT++;
        
        t = m;
        for (i=0;i<4;i++){
            temp = t[1]; t[1] = t[2]; t[2] = t[3]; t[3] = t[4]; t[4] = temp;
            IN[t] = true;
        }

        t = m;
        temp = t[0]; t[0] = t[5]; t[5] = temp;
        temp = t[2]; t[4] = t[4]; t[2] = temp;
        for (i=0;i<4;i++){
            temp = t[1]; t[1] = t[2]; t[2] = t[3]; t[3] = t[4]; t[4] = temp;
            IN[t] = true;
        }

        t = m;
        temp = t[0]; t[0] = t[1]; t[1] = t[5]; t[5] = t[3]; t[3] = temp;
        for (i=0;i<4;i++){
            temp = t[1]; t[1] = t[2]; t[2] = t[3]; t[3] = t[4]; t[4] = temp;
            IN[t] = true;
        }

        t = m;
        temp = t[0]; t[0] = t[1]; t[1] = t[5]; t[5] = t[3]; t[3] = temp;
        temp = t[0]; t[0] = t[5]; t[5] = temp;
        temp = t[2]; t[4] = t[4]; t[2] = temp;
        for (i=0;i<4;i++){
            temp = t[1]; t[1] = t[2]; t[2] = t[3]; t[3] = t[4]; t[4] = temp;
            IN[t] = true;
        }

        t = m;
        temp = t[0]; t[0] = t[2]; t[2] = t[5]; t[5] = t[4]; t[4] = temp;
        for (i=0;i<4;i++){
            temp = t[1]; t[1] = t[2]; t[2] = t[3]; t[3] = t[4]; t[4] = temp;
            IN[t] = true;
        }

        t = m;
        temp = t[0]; t[0] = t[2]; t[2] = t[5]; t[5] = t[4]; t[4] = temp;
        temp = t[0]; t[0] = t[5]; t[5] = temp;
        temp = t[2]; t[4] = t[4]; t[2] = temp;
        for (i=0;i<4;i++){
            temp = t[1]; t[1] = t[2]; t[2] = t[3]; t[3] = t[4]; t[4] = temp;
            IN[t] = true;
        }
    }
    else{
        for (i=0;i<6;i++) if (CHK[i] == 0){
            CHK[i] = 1; go(v+1,m+C[i]); CHK[i] = 0;
        }
    }
}

int main()
{
    cin >> C;

    go(0,"");

    printf ("%d\n",CNT);

    return 0;
}