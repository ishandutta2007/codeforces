#include <iostream>
#include <vector>
#include <map>
#include <cstring>
using namespace std;


#pragma comment(linker, "/STACK:160000000")

unsigned long long curv[250];
vector<int> nxt[500500];
unsigned long long SSID[500500];
int koef=28;
vector <int> opened;
int qu[500500][2];

void main()
{
    SSID[0]=1ULL-1;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    char c;
    char cn[15];
    
    int num=1;
    opened.push_back(0);
    while (scanf("%c",&c)!=173 && c!='\n')
    {
        unsigned long long ssid=0;
        scanf("%[^>]s",cn);
        int cl=strlen(cn);
        if (cn[0]=='/')
        {
            opened.pop_back();
        }
        else if (cn[cl-1]=='/')
        {
            for (int i=0;i<cl-1;i++)
            {
                ssid*=28;
                ssid+=cn[i]-'a'+1;
            }
            SSID[num]=ssid;
            nxt[opened[opened.size()-1]].push_back(num);
            //previous[num]=opened[opened.size()-1];
            //SSID2POS[ssid].push_back(num);
            num++;
        }
        else
        {
            for (int i=0;i<cl;i++)
            {
                ssid*=28;
                ssid+=cn[i]-'a'+1;
            }
            SSID[num]=ssid;
            nxt[opened[opened.size()-1]].push_back(num);
            //previous[num]=opened[opened.size()-1];
            //SSID2POS[ssid].push_back(num);
            opened.push_back(num);
            num++;
        }
        scanf("%c",&c);
    }
    int n;
    scanf("%d\n",&n);
    for (int i=0;i<n;i++)
    {
        int curl=0;
        char c;
        

        do
        {
            scanf("%s",cn);
            c='?';
            int cl=strlen(cn);
            unsigned long long ssid=0;
            for (int j=0;j<cl;j++)
            {
                ssid*=28;
                ssid+=cn[j]-'a'+1;
            }
            curv[curl++]=ssid;
        } 
        while (scanf("%c",&c) && c==' ');




        int ans=0;

        int l=0,r=1;
        qu[0][0]=0;
        qu[0][1]=0;

        while (l<r)
        {
            int curvert=qu[l][0];
            int curd=qu[l++][1];

            if (curd==curl-1 && SSID[curvert]==curv[curd])
                ans++;
            if (curd<curl-1 && SSID[curvert]==curv[curd])
                curd++;
            int len=nxt[curvert].size();
            for (int ii=0;ii<len;ii++)
            {
                qu[r][0]=nxt[curvert][ii];
                qu[r++][1]=curd;
            }
        }
        
        printf("%d\n",ans);
    }

}