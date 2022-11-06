var
c:array[1..1000010]of int64;
t1,n,i,j:longint;
t,k:int64;
function gcd(a,b:longint):longint;
begin
while(a>0)and(b>0)do if a>b then a:=a mod b else b:=b mod a;
gcd:=a+b;
end;
begin
read(n,k);
if k=1 then  write('Yes') else begin
for i:=1 to n do read(c[i]) ;
t:=1;
for i:=1 to n       do
begin
t:=((t*c[i])div gcd(t,c[i]))mod k;
end;
if t=0 then write('Yes') else write('No');
end;
end.