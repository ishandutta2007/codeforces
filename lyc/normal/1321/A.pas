var n,l,r,mid,ans:int64;i:longint;a,b:array[0..1000]of longint;
function check(k:longint):boolean;
var i:longint;s1,s2:int64;
begin
  s1:=0;s2:=0;
  for i:=1 to n do
    if a[i] xor b[i]<>0 then
    begin
      if a[i]=1 then s1:=s1+k else s2:=s2+1;
    end;
  if s1>s2 then ans:=k;
  exit(s1>s2);
end;
begin
  readln(n); ans:=maxlongint; 
  for i:=1 to n do
    read(a[i]);
  for i:=1 to n do
    read(b[i]);
  l:=1;r:=maxlongint;
  while l<=r do
  begin
    mid:=l+(r-l) div 2;
    if check(mid) then
      r:=mid-1 else l:=mid+1;
  end;
  if ans=maxlongint then writeln(-1) else writeln(ans);
end.