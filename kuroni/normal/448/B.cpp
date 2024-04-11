#include <bits/stdc++.h>

char s[100], t[100];

using namespace std;

bool arr(int is, int it)
{
    int i;
    bool check = false;
    if (it == strlen(t)) return true;
    if (is == strlen(s)) return false;
    for (i = is; i < strlen(s);i++)
    {
        if (s[i] == t[it]) {check = true; break;}
    }
    if (!(check)) return false; else return(arr(i+1,it+1));
}

int main()
{
    string tmp;
    bool need = false;
    getline(cin,tmp);
    strcpy(s, tmp.c_str());
    getline(cin,tmp);
    strcpy(t, tmp.c_str());
    int A[26];
    memset(A,0,sizeof(A));
    for (int i=0;i<strlen(s);i++) A[int(s[i])-97]++;
    for (int i=0;i<strlen(t);i++)
    {
        A[int(t[i])-97]--;
        if (A[int(t[i])-97] < 0) {need = true; break;}
    }
    if (need) cout<<"need tree";
    else
    {
        if (strlen(s) == strlen(t)) cout<<"array";
        else
        {
            if (arr(0,0)) cout<<"automaton"; else cout<<"both";
        }
    }
    return 0;
}