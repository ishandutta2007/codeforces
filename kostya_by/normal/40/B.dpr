program Project1; 
 
{$APPTYPE CONSOLE} 
 
var 
  a,b,m,n,ans,ans1,s,x:LongInt; 
begin 
  Readln(n,m); 
  Readln(x); 
  Dec(x); 
  a:=n; 
  b:=m; 
  n:=n-(2*x); 
  m:=m-(2*x); 
  ans:=0; 
  if (n>0) and (m>0) then 
  begin 
    s:=n*m; 
    ans:=s div 2; 
    if s mod 2=1 then Inc(ans); 
    Inc(x); 
    a:=a-(2*x); 
    b:=b-(2*x); 
    ans1:=0; 
    if (a>0) and (b>0) then 
    begin 
    s:=a*b; 
    ans1:=s div 2; 
    if s mod 2=1 then Inc(ans1); 
    end; 
    ans:=ans-ans1;
  end; 
  Writeln(ans); 
  readln; 
end.