#include<bits/stdc++.h>
using namespace std;

map<string,int> seen;

int main()
{
    int id=0;

    for(char a='a';a<='z';a++)
        for(char b='a';b<='z';b++)
            if(a!=b)
            {
                id++;

                string cur="";
                cur.push_back(a);
                cur.push_back(b);

                seen[cur]=id;
            }

    int t;
    cin>>t;

    while(t)
    {
        t--;

        string cur;
        cin>>cur;

        cout<<seen[cur]<<endl;
    }
    return 0;
}