program project1;

var
   words : array[1..10000] of longint;
   bool : array[-1..5] of longint;
   i,j,k,n,m,r,t : longint;
   st,s1 : string;
   s : ansistring;
   ch : char;
begin
     read(s);
     st:='';
     j:=1;
     words[1]:=0;
     r:=0;
     t:=0;
     for i:=1 to length(s) do begin
         if s[i] <> ' ' then begin
            st:=s[i] + st;
         end;
         if s[i] = ' ' then begin
            if st = '' then continue;
            s1:=copy(st,1,3);
            if s1 = 'rte' then begin
                words[j]:=2;
                inc(r);
            end;
            s1:=copy(st,1,4);
            if s1 = 'soil' then begin
                words[j]:=1;
                inc(r);
            end;
            if s1 = 'arte' then begin
                words[j]:=2;
                inc(t);
            end;
            s1:=copy(st,1,5);
            if s1 = 'alail' then begin
                words[j]:=1;
                inc(t);
            end;
            s1:=copy(st,1,6);
            if s1 = 'sitini' then begin
                words[j]:=3;
                inc(r);
            end;
            if s1 = 'setini' then begin
                words[j]:=3;
                inc(t);
            end;
            if words[j] = 0 then begin
               writeln('NO');
               halt(0);
            end;
            inc(j);
            st:='';
         end;
     end;
     s1:=copy(st,1,3);
     if s1 = 'rte' then begin
        words[j]:=2;
            inc(r);
        end;
     s1:=copy(st,1,4);
     if s1 = 'soil' then begin
            words[j]:=1;
            inc(r);
        end;
     if s1 = 'arte' then begin
            words[j]:=2;
            inc(t);
        end;
     s1:=copy(st,1,5);
     if s1 = 'alail' then begin
            words[j]:=1;
            inc(t);
        end;
     s1:=copy(st,1,6);
     if s1 = 'sitini' then begin
            words[j]:=3;
            inc(r);
        end;
     if s1 = 'setini' then begin
            words[j]:=3;
            inc(t);
        end;
     if words[j] = 0 then begin
        writeln('NO');
        halt(0);
     end;
     if (words[j] = 0) or (r * t <> 0) then begin
        writeln('NO');
        halt(0);
     end;
     st:='';
     if j = 1 then begin
        writeln('YES');
        halt(0);
     end;
     bool[1]:=0;
     bool[2]:=0;
     bool[3]:=0;
     bool[4]:=0;
     bool[5]:=0;
     n:=j;
     for i:=1 to n do begin
         if (bool[words[i] + 1] <> 0) or (bool[words[i] + 2] <> 0) then begin
            writeln('NO');
            halt(0);
         end;
         inc(bool[words[i]]);
     end;
     if (bool[2] = 1) then writeln('YES') else writeln('NO');
end.