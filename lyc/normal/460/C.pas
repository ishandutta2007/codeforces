var w,n,m,i,l,r,mid,ans,x:longint;a,b:array[0..500000]of longint;
function cx(x:longint):longint;
var sum:longint;
begin
  sum:=0;
  while x>0 do
  begin
    sum:=sum+a[x];
    x:=x-(x and -x);
  end;
  exit(sum); 
end;
procedure xg(x,y:longint);
begin
  while x<=n do
  begin
    a[x]:=a[x]+y;
    x:=x+(x and -x);
  end;
end;
function check(k:longint):boolean;
var t,i:longint;
begin
  t:=0;
  for i:=1 to n do
  begin
    while cx(i)<k do
    begin
      xg(i,1);
      xg(i+w,-1);
      inc(t);
      if t>m then
      begin
        a:=b;
        exit(false);
      end;
    end;
  end;
  if t>m then
  begin
    a:=b;exit(false);
  end;
  a:=b;
  exit(true);
end;
begin
  readln(n,m,w);
  for i:=1 to n do
  begin
    read(x);
    xg(i,x);
    xg(i+1,-x);
  end;
  b:=a;
  l:=0;r:=maxlongint;
  while l<=r do
  begin
    mid:=l+(r-l) div 2;
    if check(mid) then
    begin
      ans:=mid;
      l:=mid+1;
    end else r:=mid-1;
  end;
  writeln(ans);
end.