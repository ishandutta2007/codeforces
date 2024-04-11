var kitten,f,I,a=0,t,m=[],i,s,s1=readline().split(' ');
for(i=0;i<19;i++)m.push(0);
f=s1[0];
I=s1[1];
t=s1[2];
for (var i=0;i<f;i++)
{s=readline();
for (var j=0;j<I;j++)
if (s[j]=='Y') m[j]++;}
for (var i=0;i<I;i++)if(m[i]>=t)a++;
print(a);