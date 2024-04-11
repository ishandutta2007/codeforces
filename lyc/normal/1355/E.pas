var x,y,m,l,r,mid,v2,v1,ans,qq:int64;n,i:longint;a:array[0..200000]of longint;
function max(x,y:int64):int64;
begin
  if x>y then exit(x) else exit(y);
end;
function min(x,y:int64):int64;
begin
  if x<y then exit(x) else exit(y);
end;
function check(k:int64):int64;
var q1,q2,t,re:int64;i:longint;
begin
  check:=0;
  q1:=0;q2:=0;re:=0;
  for i:=1 to n do
    if a[i]<k then q2:=q2+k-a[i] else if a[i]>k then q1:=q1+a[i]-k;
  if q2<=q1 then
  begin
    re:=qq*q2;
    q1:=q1-q2;
    q2:=0;
  end else
  begin
    re:=qq*q1;
    q2:=q2-q1;
    q1:=0;
  end;        
  exit(re+q1*y+q2*x);
end;
begin
  readln(n,x,y,m);l:=maxlongint;r:=-l;
  qq:=min(x+y,m);
  for i:=1 to n do
  begin
    read(a[i]);
    l:=min(l,a[i]);
    r:=max(r,a[i]);
  end;
  while l<r do
  begin
    mid:=l+(r-l) div 2;
    v1:=check(mid);
    v2:=check(mid+1);
    ans:=min(v1,v2);
    if v1<v2 then r:=mid else l:=mid+1;
  end;
  writeln(ans);
end.