program project1;

const exp = 1e-12;

type tside = record
     name : string;
     exp : longint;
end;

var
   side : array[1..40] of tside;
   i,j,n,m,h,kn : longint;
   k : real;
   st : string;
   ch : char;
   fl : boolean;

procedure sort(l,r : longint);
var
   i,j : longint;
   x,y : tside;
begin
     i:=l;
     j:=r;
     x:=side[(l + r) div 2];
     repeat
           while side[i].name < x.name do inc(i);
           while side[j].name > x.name do dec(j);
           if i <= j then begin
              y:=side[i]; side[i]:=side[j]; side[j]:=y;
              inc(i);
              dec(j);
           end;
     until i > j;
     if i < r then sort(i,r);
     if l < j then sort(l,j);
end;

begin
     readln(n,m,k);
     h:=0;
     for i:=1 to n do begin
         st:='';
         read(ch);
         while ch <> ' ' do begin
               st:=st + ch;
               read(ch);
         end;
         readln(j);
         if trunc(k * j + exp) < 100 then continue;
         inc(h);
         side[h].name:=st;
         side[h].exp:=trunc(k * j + exp);
     end;
     for i:=1 to m do begin
         readln(st);
         fl:=false;
         for j:=1 to h do begin
             if st = side[j].name then fl:=true;
         end;
         if fl then continue;
         inc(h);
         side[h].name:=st;
         side[h].exp:=0;
     end;
     sort(1,h);
     writeln(h);
     for i:=1 to h do begin
         writeln(side[i].name,' ',side[i].exp);
     end;
end.