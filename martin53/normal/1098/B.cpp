#include<bits/stdc++.h>
using namespace std;
vector< vector<char> > inp,output;
int n,m;
char all[4]={'A','C','G','T'};
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();
cin>>n>>m;
char x;
for(int i=1;i<=n;i++)
{
    vector<char> v={};
    for(int j=1;j<=m;j++)
    {
        cin>>x;
        v.push_back(x);
    }
    inp.push_back(v);
    output.push_back(v);
}

int best=0;
//rows
for(int t1=0;t1<4;t1++)
    for(int t2=0;t2<4;t2++)
        for(int t3=0;t3<4;t3++)
            for(int t4=0;t4<4;t4++)
            if(t1!=t2&&t1!=t3&&t1!=t4&&t2!=t3&&t2!=t4&&t3!=t4)
            {
                int now=0;
                for(int i=0;i<n;i++)
                {
                    int option[2]={0,0};
                    for(int j=0;j<m;j++)
                        if(i%2==0)
                        {
                            if(inp[i][j]==all[t1])option[j%2]++;
                            if(inp[i][j]==all[t2])option[!(j%2)]++;
                        }
                        else
                        {
                            if(inp[i][j]==all[t3])option[j%2]++;
                            if(inp[i][j]==all[t4])option[!(j%2)]++;
                        }
                    now=now+max(option[0],option[1]);
                }
                best=max(best,now);
            }
//columns
for(int t1=0;t1<4;t1++)
    for(int t2=0;t2<4;t2++)
        for(int t3=0;t3<4;t3++)
            for(int t4=0;t4<4;t4++)
            if(t1!=t2&&t1!=t3&&t1!=t4&&t2!=t3&&t2!=t4&&t3!=t4)
            {
                int now=0;
                for(int j=0;j<m;j++)
                {
                    int option[2]={0,0};
                    for(int i=0;i<n;i++)
                        if(j%2==0)
                        {
                            if(inp[i][j]==all[t1])option[i%2]++;
                            if(inp[i][j]==all[t3])option[!(i%2)]++;
                        }
                        else
                        {
                            if(inp[i][j]==all[t2])option[i%2]++;
                            if(inp[i][j]==all[t4])option[!(i%2)]++;
                        }
                    now=now+max(option[0],option[1]);
                }
                best=max(best,now);
            }








//rows
for(int t1=0;t1<4;t1++)
    for(int t2=0;t2<4;t2++)
        for(int t3=0;t3<4;t3++)
            for(int t4=0;t4<4;t4++)
            if(t1!=t2&&t1!=t3&&t1!=t4&&t2!=t3&&t2!=t4&&t3!=t4)
            {
                int now=0;
                for(int i=0;i<n;i++)
                {
                    int option[2]={0,0};
                    for(int j=0;j<m;j++)
                        if(i%2==0)
                        {
                            if(inp[i][j]==all[t1])option[j%2]++;
                            if(inp[i][j]==all[t2])option[!(j%2)]++;
                        }
                        else
                        {
                            if(inp[i][j]==all[t3])option[j%2]++;
                            if(inp[i][j]==all[t4])option[!(j%2)]++;
                        }
                    now=now+max(option[0],option[1]);
                }
                if(now==best)
                {
                    for(int i=0;i<n;i++)
                    {
                    int option[2]={0,0};
                    for(int j=0;j<m;j++)
                        if(i%2==0)
                        {
                            if(inp[i][j]==all[t1])option[j%2]++;
                            if(inp[i][j]==all[t2])option[!(j%2)]++;
                        }
                        else
                        {
                            if(inp[i][j]==all[t3])option[j%2]++;
                            if(inp[i][j]==all[t4])option[!(j%2)]++;
                        }
                    if(option[0]>option[1])
                    {
                        for(int j=0;j<m;j++)
                            if(i%2==0&&j%2==0)cout<<all[t1];
                            else if(i%2==0&&j%2==1)cout<<all[t2];
                            else if(i%2==1&&j%2==0)cout<<all[t3];
                            else if(i%2==1&&j%2==1)cout<<all[t4];
                    }
                    else
                    {
                        for(int j=0;j<m;j++)
                            if(i%2==0&&j%2==1)cout<<all[t1];
                            else if(i%2==0&&j%2==0)cout<<all[t2];
                            else if(i%2==1&&j%2==1)cout<<all[t3];
                            else if(i%2==1&&j%2==0)cout<<all[t4];
                    }
                    cout<<endl;

                    }
                    exit(0);


                }
            }

//columns
for(int t1=0;t1<4;t1++)
    for(int t2=0;t2<4;t2++)
        for(int t3=0;t3<4;t3++)
            for(int t4=0;t4<4;t4++)
            if(t1!=t2&&t1!=t3&&t1!=t4&&t2!=t3&&t2!=t4&&t3!=t4)
            {
                int now=0;
                for(int j=0;j<m;j++)
                {
                    int option[2]={0,0};
                    for(int i=0;i<n;i++)
                        if(j%2==0)
                        {
                            if(inp[i][j]==all[t1])option[i%2]++;
                            if(inp[i][j]==all[t3])option[!(i%2)]++;
                        }
                        else
                        {
                            if(inp[i][j]==all[t2])option[i%2]++;
                            if(inp[i][j]==all[t4])option[!(i%2)]++;
                        }
                    now=now+max(option[0],option[1]);
                }
                best=max(best,now);









                if(now==best)
                {
                    //cout<<t1<<" "<<t2<<" "<<t3<<" "<<t4<<endl;
                    for(int j=0;j<m;j++)
                    {
                    int option[2]={0,0};
                    for(int i=0;i<n;i++)
                        if(j%2==0)
                        {
                            if(inp[i][j]==all[t1])option[i%2]++;
                            if(inp[i][j]==all[t3])option[!(i%2)]++;
                        }
                        else
                        {
                            if(inp[i][j]==all[t2])option[i%2]++;
                            if(inp[i][j]==all[t4])option[!(i%2)]++;
                        }

                    //cout<<j<<" "<<option[0]<<" "<<option[1]<<endl;

                    if(option[0]>option[1])
                    {
                        for(int i=0;i<n;i++)
                            if(i%2==0&&j%2==0)output[i][j]=all[t1];
                            else if(i%2==0&&j%2==1)output[i][j]=all[t2];
                            else if(i%2==1&&j%2==0)output[i][j]=all[t3];
                            else if(i%2==1&&j%2==1)output[i][j]=all[t4];
                    }
                    else
                    {
                        for(int i=0;i<n;i++)
                            if(i%2==1&&j%2==0)output[i][j]=all[t1];
                            else if(i%2==1&&j%2==1)output[i][j]=all[t2];
                            else if(i%2==0&&j%2==0)output[i][j]=all[t3];
                            else if(i%2==0&&j%2==1)output[i][j]=all[t4];
                    }

                    /*
                    for(int i=0;i<n;i++)
                        cout<<output[i][j];cout<<endl;
                    */

                    }

                    for(auto k:output)
                    {
                        for(auto p:k)cout<<p;
                        cout<<endl;
                    }
                    exit(0);
                }
}
































return 0;
}