var ans,n,i,j,x:longint;b:array[1..100000]of int64;
function check(i,j:longint):longint;
var d,s,now:int64;k:longint;
begin
  s:=abs(i)+abs(j);
  d:=(b[2]+j)-(b[1]+i);
  now:=b[2]+j;
  for k:=3 to n do
  begin
    now:=now+d;
    if abs(b[k]-now)<=1 then inc(s,abs(b[k]-now))
    else exit(n+1);
  end;
  exit(s);
end;
begin
  read(n);
  if n<=2 then begin writeln(0);exit;end;
  for i:=1 to n do read(b[i]);
  ans:=n+1;
  for i:=-1 to 1 do
    for j:=-1 to 1 do
    begin
      x:=check(i,j);
      if x<ans then ans:=x;
    end;
  if ans=n+1 then writeln(-1)
  else writeln(ans);
end.