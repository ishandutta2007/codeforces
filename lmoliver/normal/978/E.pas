var n,w,i,ans:longint;a:array[1..1000]of longint;now,max,min:int64;
begin
  read(n,w);
  for i:=1 to n do read(a[i]);
  for i:=1 to n do
  begin
    now:=now+a[i];
    if now>max then max:=now;if now<min then min:=now;
  end;
  ans:=w-max+min+1;
  if ans<=0 then writeln(0)else writeln(ans);
end.