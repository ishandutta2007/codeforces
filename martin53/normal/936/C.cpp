#include<bits/stdc++.h>
using namespace std;
string a,b;
void shift(string &now,int x)
{
    a="",b="";
    int SZ=now.size();

    for(int i=0;i<SZ-x;i++)
        a.push_back(now[i]);

    for(int i=SZ-x;i<SZ;i++)
        b.push_back(now[i]);

    reverse(b.begin(),b.end());
    now=b+a;
}
string my,target;
int there[26];
void brute()
{
    string my=/*"cdefaghbij"*//*"cdefaghbij"*/"efaghbijcd";
int SZ=my.size();
for(int i=0;i<=my.size();i++)
{
    string mem_i=my;
    shift(my,i);
    for(int j=0;j<=my.size();j++)
    {
        string mem_j=my;
        shift(my,j);
            for(int k=0;k<=my.size();k++)
                for(int l=0;l<=my.size();l++)
                    for(int p=0;p<=my.size();p++)
                        //for(int q=0;q<=my.size();q++)
                        {
                            string now=my;
                            shift(now,k);
                            shift(now,l);
                            shift(now,p);
                            //shift(now,q);

                            if(now[SZ-4]=='a'/*'b'*/&&now[SZ-3]=='b'/*'a'*/&&now[SZ-2]=='c'&&now[SZ-1]=='d')
                            //if(now[0]=='c'&&now[1]=='d'&&now[2]==/*'b'*/'a'&&now[3]==/*'b'*/'a')
                            {
                                string help="efaghbijcd";
                                shift(help,i);
                                cout<<help<<endl;

                                shift(help,j);
                                cout<<help<<endl;

                                shift(help,k);
                                cout<<help<<endl;

                                shift(help,l);
                                cout<<help<<endl;

                                shift(help,p);
                                cout<<help<<endl;
                            cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<p<<endl;
                            //cout<<now<<endl;
                            }
                        }
        my=mem_j;
    }
    my=mem_i;
}
exit(0);
}
vector<int> output={};
void add(int SZ)
{
    shift(my,SZ);
    output.push_back(SZ);
}
int main()
{
//brute();
int n;
cin>>n;
cin>>my>>target;

for(auto k:my)
    there[k-'a']++;
for(auto k:target)
    there[k-'a']--;

for(int i=0;i<26;i++)
    if(there[i])
    {
        cout<<-1<<endl;
        return 0;
    }

for(int i=n-2;i>=0;i=i-2)
{
    int A,M=1,B,N=1,C,D=(n-i-2);

    int where_M,where_N;
    for(int j=0;true;j++)
        if(my[j]==target[i])
        {
            where_M=j;
            break;
        }

    for(int j=0;true;j++)
        if(my[j]==target[i+1]&&j!=where_M)
        {
            where_N=j;
            break;
        }
    if(where_M<where_N)A=where_M,B=where_N-A-M;
    else A=where_N,B=where_M-A-M;

    C=n-A-M-B-N-D;

    //cout<<where_M<<" "<<where_N<<endl;

    //cout<<A<<" "<<M<<" "<<B<<" "<<N<<" "<<C<<" "<<D<<endl;

    if(where_M<where_N)
    {
        add(B+N+C+D);
        add(C+N+B+A+M);
        add(N+C+D);
        add(N+M+A+B);
        add(C);
    }

    else
    {
        add(C+D);
        add(C+A+N+B+M);
        add(N+A+C+D);
        add(N+M+B);
        add(C+A);
    }

    //cout<<"after "<<i<<" -> ";cout<<my<<endl;
}

assert(my==target);
cout<<output.size()<<endl;
for(auto k:output)cout<<k<<" ";cout<<endl;
return 0;
}