var s:string; i,k:longint; c:boolean;
    a:array[1..5] of char; 
begin

k:=1;
 a[1]:='h';
 a[2]:='e';
 a[3]:='l';
 a[4]:='l';
 a[5]:='o';
readln(s);C:=false;
for i:=1 to length(s) do begin
 if s[i]=a[k] then k:=k+1;
 if k=6 then begin c:=true; break; end; end; 
if c then writeln('YES') else writeln('NO'); 

end.