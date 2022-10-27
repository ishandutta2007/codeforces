#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<ctime>
#include<queue>
using namespace std;
#define int long long
#define mn 100005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test" 
#define pii pair <int, int>
#define XX first
#define YY second

string ans;
int n, secCase=1;
//testcases initials
void initial()
{
    cin>>n;
    ans.assign(n+1, '?');
    secCase=1;
}

int interactAndFill(string S) //return 0 if no strings
{
    cout<<"? "<<S<<endl;
    int sz;
    cin>>sz;
    int ret=sz;
    while (sz--)
    {
        int u;
        cin>>u;
        for (int i=u; i<u+S.size(); i++) ans[i]=S[i-u];
    }
    return ret;
}

int output()
{
    cout<<"! "<<ans.substr(1, n)<<endl;
    int k;
    cin>>k;
    if (k==0) exit(0);
}

//first interactions: CO, HO, CH, HC
void firstInteractions()
{
    int b=interactAndFill("CO");
    if (b!=0) secCase=0;
    b=interactAndFill("HO");
    if (b!=0) secCase=0;
    b=interactAndFill("CH");
    if (b!=0) secCase=0;
    b=interactAndFill("HC");
    if (b!=0) secCase=0;
    
}

//solve first case: for i=3 to n, we will try to ask just once for each i as a length
void solveFirstCase()
{
    //The mechanics here is relying on the appearance of some strings, then use them to lower the costs of finding 
    //still-absent letters around it.

    //Call the position of the last-found letter in the string K, we'll iterate from K to 1 and try to solve for
    //all still-absent letters before K. For each letter, with some careful casework, we only have to use 0 or 1 
    //question to it.

    //If the K-th position in the string is either 'C' or 'H', it can be proved that all letter after K is equal to
    //it

    //Else, we can continually ask if the next letter is 'O'. If it is, continue to ask if the next letter is 'O',
    //and if it isn't, we can ask one more question to find out if it is 'C' or 'H', then you can fill the rest of
    //it using no more questions.

    int k=n;
    while (ans[k]=='?') k--; 
    int ptr=k;
    while (ptr>1)
    {
        ptr--;
        if (ans[ptr]!='?') continue;
        if (ans[ptr+1]=='H') //this case, ans[ptr] cannot be 'C', because if it is, it should have been found before
        {
            interactAndFill("O"+ans.substr(ptr+1, k-ptr));
            if (ans[ptr]=='?') ans[ptr]='H';
        }
        else if (ans[ptr+1]=='C') //same as 'H', ans[ptr] cannot be 'H'
        {
            interactAndFill("O"+ans.substr(ptr+1, k-ptr));
            if (ans[ptr]=='?') ans[ptr]='C';
        }
        else //this doesn't require any casework. If ans[ptr+1] is 'O', ans[ptr] should've found before or ans[ptr] is 'O'
        {
            ans[ptr]='O';
        }
    }

    //Now all letter in pos from 1 to K should've been found, we can continue to work on K+1 to N
    for (int i=k+1; i<=n; i++)
    {
        interactAndFill(ans.substr(1, i-1)+"O");
        if (ans[i]=='?')
        {
            char rest='C';
            interactAndFill(ans.substr(1, i-1)+"C");
            if (ans[i]=='?') rest='H';
            for (int j=i; j<=n; j++) ans[j]=rest;
            break;
        }
    }

    output();
}

//solve second case (no strings found after first several interactions)
void solveSecondCase()
{
    int b=interactAndFill("OOO");
    if (b>0)
    {
        for (int i=1; i<=n; i++) if (ans[i]=='?') ans[i]='C';
        int c=interactAndFill(ans.substr(1, n));
        if (c==0) for (int i=1; i<=n; i++) if (ans[i]=='C') ans[i]='H';
    }
    else
    {
        b=interactAndFill("HHH");
        if (b==0)
        {
            int c=interactAndFill("CCC");
            //special case, only happen for n==4
            if (c==0)
            {
                int d=interactAndFill("OOCC");
                if (d==0) ans=" OOHH";
                else ans=" OOCC";
            }
            else for (int i=1; i<=n; i++) if (ans[i]=='?') ans[i]='O';
        }
        else for (int i=1; i<=n; i++) if (ans[i]=='?') ans[i]='O';
    }
    output();
}

signed main()
{
    int T;
    cin>>T;
    while (T--)
    {
        initial();
        firstInteractions();
        // cerr<<"CASE: "<<secCase<<endl;
        if (secCase==1) solveSecondCase();
        else solveFirstCase();
    }
    exit(0);
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/