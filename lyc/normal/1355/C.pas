var a,b,c,d,i,yn,ym,ans:int64;a1:array[0..2000005]of int64;
function max(x,y:int64):int64;
begin
  if x>y then exit(x) else exit(y);
end;
function min(x,y:int64):int64;
begin
  if x<y then exit(x) else exit(y);
end;
begin
  readln(a,b,c,d);
  a1[b+c+1]:=0;
  i:=b+c;
  while i>=c do
  begin
    yn:=max(i-b,b);
    ym:=max(min(i-a,c),yn-1);
    a1[i]:=a1[i+1]+ym-yn+1;
    if i<=d then ans:=ans+a1[i+1];
    dec(i);
  end;
  writeln(ans);
end.