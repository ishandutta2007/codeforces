var s,g:string; k,i,j:integer; b:char; e:boolean;
begin
readln(s);
b:='a';
g:='aoyuie';
i:=1;
while (i<=length(s)) do begin
 e:=true;
 if s[i]<'a' then s[i]:=chr(ord(s[i])+32);
 for j:=1 to length(g) do
  if s[i]=g[j] then begin delete(s,i,1); e:=false;break; end;
 
 if e then begin insert('.',s,i); i:=i+2; end;
 end;
writeln;
writeln(s);
end.