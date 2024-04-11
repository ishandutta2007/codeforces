var t,i,n,x,j,ans:longint;f,f1:array[0..100000]of longint;ch:char;
begin
  readln(t);
  for i:=1 to t do
  begin
    readln(n,x);f[0]:=0;f1[0]:=0;ans:=0;
    for j:=1 to n do
    begin
      read(ch);
      f[j]:=f[j-1];f1[j]:=f1[j-1];
      if ch='1' then inc(f1[j]) else inc(f[j]);
      if f[j]-f1[j]=x then inc(ans);
    end;
    if (f[n]=f1[n]) then
    begin
      if ans=0 then writeln(0) else writeln(-1);
      readln;
      continue;
    end else
    begin
      if x=0 then inc(ans);
      for j:=1 to n do
        if ((x-f[j]+f1[j]) mod (f[n]-f1[n])=0)and((x-f[j]+f1[j])/(f[n]-f1[n])>=1) then
        begin
          inc(ans);
        end;
      writeln(ans);
      readln;
    end;
  end;
end.